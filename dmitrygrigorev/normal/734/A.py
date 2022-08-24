n = input()
a = input()
f = 0
s = 0
for i in range(len(a)):
    if (a[i] == "A"):
        f += 1
    else:
        s += 1
if f > s:
    print("Anton")
if f < s:
    print("Danik")
if f == s:
    print("Friendship")