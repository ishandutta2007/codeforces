I=lambda:map(int,input().split())
n,m=I()
s=0
p=1
for v in I():s+=(v-p)%n;p=v
print(s)