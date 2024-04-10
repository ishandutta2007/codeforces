a=input()
pwd=[]
for x in range(a):
    n=raw_input()
    if(n=='pwd'):
        if(pwd==[]):print '/'
        else:print '/'+'/'.join(pwd)+'/'
    else:
        n=n[3:]
        if(n[0]=='/'):
            pwd=[]
            n=n[1:]
        com=n.split('/')
        for x in com:
            if(x=='..'):pwd.pop()
            else:pwd+=[x]