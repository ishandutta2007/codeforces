from sys import exit
n = int(input())
p = list(map(int, input().split()))

for i, cur_p in zip(range(n), p):
    s = input().strip()
    cnt = 0
    for c in s:
        if c in 'aeiouy':
            cnt+= 1
    if cnt != cur_p:
        print("NO")
        exit(0)
print("YES")