n=int(raw_input())
s=raw_input()
x=int(s)
ll=0
rr=n
for i in range(n):
    if i==0:
        continue
    if s[i] != '0':
        if i <= n//2:
            ll=i
        if i>n/2 and rr == n:
            rr=i;
an=0
if ll!=0:
    ten=10**(n-ll)
    an=x//ten+x%ten
if rr!=n:
    ten=10**(n-rr)
    res=x//ten+x%ten
    if an==0:
        an=res;
    elif res < an:
        an = res
print an