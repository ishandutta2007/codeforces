alpha = "abcdefghijklmnopqrstuvwxyz"
s = input()
line= []
for i in range(len(s)):
    line += [False]
yes = True
for i in range(len(alpha)):
    element = alpha[i]
    go = False
    for i in range(len(s)):
        if not line[i]:
            if s[i] == element:
                line[i] = True
                go = True
            else:
                if not go:
                    yes = False
                    break
if yes:
    print("YES")
else:
    print("NO")