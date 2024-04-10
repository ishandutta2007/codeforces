n,s,t = int(input()),input(),input()
ab = []
ba =[]
for i in range(n):
    if s[i]=='a' and t[i]=='b':
        ab.append(i+1)
    if s[i]=='b' and t[i]=='a':
        ba.append(i+1)
if (len(ab)+len(ba))%2:
    print(-1)
else:
    ans=[]
    ans+=[(ab[2*a],ab[2*a+1]) for a in range(len(ab)//2)]
    ans+=[(ba[2*a],ba[2*a+1]) for a in range(len(ba)//2)]
    if len(ab)%2:
        ans+=[(ab[-1],ab[-1]),(ba[-1],ab[-1])]
    print(len(ans))
    print('\n'.join(f'{i[0]} {i[1]}'for i in ans))