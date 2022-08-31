string = input()
now = 0
for i in range(len(string)):
    if now == 0 and string[i] == "h":
        now += 1
    if now == 1 and string[i] == "e":
        now += 1
    if now == 2 and string[i] == "i":
        now += 1
    if now == 3 and string[i] == "d":
        now += 1
    if now == 4 and string[i] == "i":
        now += 1
if now == 5:
    print("YES")
else:
    print("NO")