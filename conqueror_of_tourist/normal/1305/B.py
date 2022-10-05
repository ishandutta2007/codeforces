s = input()
n = len(s)

out = []
left = []
right = []

for i in range(n):
    if s[i] == '(':
        left.append(i)
    else:
        right.append(i)

left.reverse()

while left and right and left[-1] < right[-1]:
    out.append(left.pop())
    out.append(right.pop())

if out:
    print(1)
    print(len(out))
    print(' '.join(map(lambda x: str(x + 1), sorted(out))))
else:
    print(0)