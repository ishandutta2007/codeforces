t = int(input())
for _ in range(t):
    s = input()
    n = len(s)
    same = True
    for i in range(n):
        if s[i] != s[0]:
            same = False
    if same:
        print(s[0]*n)
    else:
        print('10'*n)