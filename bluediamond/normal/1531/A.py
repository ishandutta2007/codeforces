final,c="blue",0
for _ in range(int(input().strip())):
    a=input().strip()
    if a=="lock":c=-1
    elif a=="unlock":c=0
    elif c==0: final=a
print(final)