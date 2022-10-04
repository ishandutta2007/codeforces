s = input()
m = s.split(' ')
k = int(m[0])
a = int(m[1])
b = int(m[2])
ost = a % k
if ost == 0:
    f2 = a
else:
    f2 = a + (k-ost)
ans = ((b-f2)//k)+1
print(ans)