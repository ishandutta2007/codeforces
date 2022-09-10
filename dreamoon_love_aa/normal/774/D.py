n,l,r = map(int,input().strip().split())
a = [int(x) for x in input().split()] 
b = [int(x) for x in input().split()] 
l = l - 1
for i in range(n):
    if (i < l or i >= r) and a[i] != b[i]:
        print ("LIE")
        exit()
a = a[l:r]
b = b[l:r]
a.sort()
b.sort()
if a == b:
    print ("TRUTH")
else:
    print ("LIE")