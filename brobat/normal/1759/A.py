t = str()
for i in range(20):
    t = t + "Yes"

for _ in range(int(input())):
    s = input()
    if(t.find(s) == -1):
        print("NO")
    else:
        print("YES")