t = int(input())
outl = []

revo = [-1] * (10 ** 6 + 1)
rev = [-1] * (10 ** 6 + 1)

for _ in range(t):
    n = 2 * int(input())
    l = list(map(int, input().split()))
    #l = [pow(2, i, 12323) for i in range(n)]
    l.sort(reverse = True)

    for i in range(n-1,-1,-1):
        revo[l[i]] = i

    def rem(v):
        if v < 0: return False
        if rev[v] == -1:
            return False
        if used[rev[v]]:
            return False
        used[rev[v]] = True
        if rev[v] + 1 != n and l[rev[v] + 1] == v:
            rev[v] += 1
        return True

    for i in range(n):
        if i == 0:
            continue

        used = [False] * n
        out = [(l[0], l[i])]

        for v in l:
            rev[v] = revo[v]

        rem(l[0])
        rem(l[i])

        works = True

        curr = l[0]
        for j in range(n):
            if not used[j]:
                rem(l[j])
                if rem(curr - l[j]):
                    out.append((l[j], curr - l[j]))
                    curr = l[j]
                else:
                    works = False
                    break

        if works:
            outl.append('YES')
            outl.append(str(l[0] + l[i]))
            for u, v in out:
                outl.append(f'{u} {v}')
            break
    else:
        outl.append('NO')
        
    for v in l:
        revo[v] = -1
        rev[v] = -1
        
print('\n'.join(outl))