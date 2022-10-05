n = int(input())

parents = [0] + list(map(int,input().split()))
values = list(map(int,input().split()))

sv = values[:]

for i in range(1,n):
    if values[i] != -1:
        par = parents[i] - 1
        if sv[par] == -1:
            sv[par] = values[i]
        else:
            sv[par] = min(sv[par], values[i])
    

out = sv[0]
works = True

for i in range(1,n):
    if sv[i] != -1:
        a_val = sv[i] - sv[parents[i] - 1]
        if a_val >= 0:
            out += a_val
        else:
            works = False
            break

if works:
    print(out)
else:
    print(-1)