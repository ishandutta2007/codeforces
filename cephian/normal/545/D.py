n = int(input())
arr = list(map(int, input().split()))
arr.sort()
line = 0
sum = 0
for a in arr:
    if(a >= sum):
        sum += a
        line += 1
print(line)