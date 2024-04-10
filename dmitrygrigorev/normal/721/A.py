n = int(input())
s = input()
line = []
counter = 0
for i in range(n):
    if s[i] == "B":
        counter += 1
    else:
        if counter > 0:
            line += [counter]
        counter = 0
if counter > 0:
    line += [counter]        
if len(line) == 0:
    print(0)
else:
    print(len(line))
    print(" ".join(map(str, line)))