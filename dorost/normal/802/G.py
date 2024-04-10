s = input()
t = "heidi"
cnt = 0
for i in s:
    if cnt!=5 and i == t[cnt]: cnt+=1
if cnt < 5:
    print("NO")
else:
    print("YES")