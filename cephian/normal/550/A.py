str = input()
ab1 = ab2 = ba1 = ba2 = -1
for i in range(1, len(str)):
    if str[i-1] == 'A' and str[i] == 'B':
        if ab1 == -1:
            ab1 = i
        ab2 = i
    if str[i-1] == 'B' and str[i] == 'A':
        if ba1 == -1:
            ba1 = i
        ba2 = i

if ab1 == -1 or ba1 == -1 or not(ba2 - ab1 >= 2 or ab2 - ba1 >= 2):
    print("NO")
else:
    print("YES")