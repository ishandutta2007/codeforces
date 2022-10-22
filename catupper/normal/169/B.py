a=map(int,list(raw_input()))
b=map(int,list(raw_input()))
b.sort()
for x in range(len(a)):
    try:
        if(b[-1]>a[x]):
            a[x]=b.pop()
    except:break

print "".join(map(str,a))