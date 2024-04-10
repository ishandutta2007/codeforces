n = int(input())
cnt1 = 0
cnt2 = 0
a = [int(x) for x in raw_input().split()]
for i in a:
    if i%2==1:
        cnt1+=1
    else:
        cnt2+=1
if cnt1<cnt2 :
    ans = cnt1
else:
    ans = cnt2+ (cnt1-cnt2)//3
print(ans)