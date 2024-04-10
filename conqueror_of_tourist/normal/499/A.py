inp = input().split(' ')
num = int(inp[0])
skip = int(inp[1])
out = 0
curr = 1
for x in range(num):
    time = input().split(' ')
    start = int(time[0])
    end = int(time[1])
    while curr + skip <= start:
        curr += skip
    out += end - curr
    out += 1
    curr = end + 1
print(out)