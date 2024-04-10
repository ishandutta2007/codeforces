#constante para el mdulo del ejercicio
mod=998244353

#funcin para contar la cantidad de bits activos en la representacin en binario de k
def popcount(k):
    ans=0
    while k>0:
        ans+=(k&1)
        k>>=1
    return ans

#parte inicial de la entrada, la cantidad de elementos y la cantidad de bits
n,m=input().split()
n=int(n)
m=int(m)
#entrada de elementos del array
a=input().split()
for i in range(n):
    a[i]=int(a[i])

#array para marcar los bits que se usaron en la eliminacin gaussiana
pos=[-1 for i in range(m)]
#posicin para el pivote, al final guarda el tamao de la base xor
act=0
#se halla la base xor de a, eliminacin gaussiana
for i in range(m-1,-1,-1):
    piv=act-1
    for j in range(act,n):
        if (a[j]&(1<<i))==(1<<i):
            piv=j
            if j==act:
                break
            a[j]=a[j]+a[act]
            a[act]=a[j]-a[act]
            a[j]=a[j]-a[act]
            break
    #si piv=act-1 entonces no se encontro pivote para el bit actual
    #si este no es el caso, entonces a_act tendr al pivote
    if act-1==piv:
        continue
    else:
        pos[i]=act
        act+=1
        #se elimina el bit en cuestin en las dems posiciones de a
        for j in range(act,n):
            if (a[j]&(1<<i))==(1<<i):
                a[j]^=a[act-1]
        for j in range(0,act-1):
            if (a[j]&(1<<i))==(1<<i):
                a[j]^=a[act-1]

#se halla la potencia de 2
mul=1
for i in range(n-act):
    mul=(mul+mul)%mod

#array para la respuesta
ans=[0]*(m+1)
#solucin para el caso 1
if act<=18:
    #se generan en acs todos las posibles combinaciones de los elementos de la base
    acs=[0]*(1<<act)
    for i in range(act):
        for j in range(1<<i):
            acs[j|(1<<i)]=acs[j]^a[i]
    for i in range(1<<act):
        ans[popcount(acs[i])]+=mul
#solucin para el caso 2
else:
    #array mas pequeo para la base
    A=[a[i] for i in range(act)]
    #ahora se intercambian los bits para que los bits representativos de cada elemento de la base
    #sean los ms significativos y se puede hacer la dp ms sencillamente
    to_swap=m-1   #bit hacia el cual "mover" el representativo de un elemento
    for i in range(m-1,-1,-1):
        if pos[i]!=-1:   #se comprueba si es necesario el intercambio
            to_xor=(1<<i)^(1<<to_swap)
            for j in range(act):
                if A[j]&to_xor!=0: 
                    A[j]^=to_xor
            to_swap-=1   #notar que al realizar un cambio disminuye el bit a cambiar
    
    #matriz tridimensional sobre la que hacer la dp
    dp=[[[0 for k in range((1<<(m-act)))] for j in range(act+1)] for i in range(act+1)]
    #caso base de la dp
    dp[0][0][0]=1
    #mscara con los m-act bits menos significativos activos
    mask=(1<<(m-act))-1
    #se procede a realizar al dp
    for i in range(act):
        #parte del elemento de la base que nos interesa
        back=A[i]&mask
        for j in range(act):
            for k in range((1<<(m-act))):
                dp[i+1][j+1][k]=(dp[i][j+1][k]+dp[i][j][k^back])   #transicin general de la dp
        for k in range((1<<(m-act))):
            dp[i+1][0][k]=dp[i][0][k]      #transicin especial en la dp
    
    #array con la cantidad de bits activos para cada entero en [0,2^(m-act))
    ads=[popcount(i) for i in range((1<<(m-act)))]  
    #se halla el array solucin usando la dp calculada
    for i in range(act+1):
        for k in range((1<<(m-act))):
            ans[ads[k]+i]+=dp[act][i][k]*mul

#se aplica mdulo a la respuesta
for i in range(m+1):
    ans[i]%=mod

#se construye el output
to_os=''
for i in range(m+1):
    to_os=to_os+str(ans[i])
    if i!=m:
        to_os+=' '
print(to_os)