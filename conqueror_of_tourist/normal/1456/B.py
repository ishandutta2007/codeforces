n = int(input())

if n > 100:
    print(1)
    exit()

l = list(map(int, input().split()))
pref = [0]
for v in l:
    pref.append(pref[-1] ^ v)


best = 10 ** 5
for i in range(n):
    for j in range(i, n):
        for k in range(j + 1, n):
            xl = pref[j+1] ^ pref[i]
            xr = pref[k+1] ^ pref[j+1]
            if xr < xl and k - i < best:
                best = k - i

if best == 10 ** 5:
    print(-1)
else:
    print(best - 1)