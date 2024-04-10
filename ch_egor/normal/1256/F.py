from collections import*
h=input
q=len
r=range
f=lambda s:(Counter(s),q(set(s))==q(s)and sum(s[i]>s[j]for i in r(q(s))for j in r(i,q(s)))&1)
for _ in r(int(h())):
    n,s,t=h(),h(),h()
    print("YNEOS"[f(s)!=f(t)::2])