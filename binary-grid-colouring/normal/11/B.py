
n = int(raw_input())
n = abs(n)
cnt = 0
while n>0 or n&1:
    cnt+=1
    n-=cnt
print cnt