n = int(input())
now = 0
marker = True
for i in range(n):
    line = list(input().split())
    if (line[1] == "East" or line[1] == "West"):
        if now != 0 and now != 20000:
            continue
        else:
            marker = False
            break
    else:
        if line[1] == "North":
            now -= int(line[0]) 
        else:
            now += int(line[0])
        if not (now >= 0 and now <= 20000):
            marker = False
            break
if marker and (now == 0):
    print("YES")
else:
    print("NO")