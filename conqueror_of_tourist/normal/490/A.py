n = int(input())
l = list(map(int, input().split()))
s1 = []
s2 = []
s3 = []
for i in range(n):
    if l[i] == 1:
        s1.append(i + 1)
    elif l[i] == 2:
        s2.append(i + 1)
    else:
        s3.append(i + 1)
print(min([len(s1),len(s2),len(s3)]))
while s1 and s2 and s3:
    print(s1.pop(), s2.pop(), s3.pop())