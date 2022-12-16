TT = int(input())

for tt in range(TT):
    a = input()
    b = input()
    ans = 0
    for i in range(len(a)):
        for j in range(len(b)):
            r = 0
            while r+i < len(a) and r+j < len(b) and a[r+i] == b[r+j]:
                r += 1
            ans = max(ans, r)
    print(len(a)+len(b)-2*ans)