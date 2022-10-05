t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    curr = 0
    out = 0
    for c in s:
        if c == '(':
            curr += 1
        else:
            if curr:
                curr -= 1
            else:
                out += 1
    print(out)