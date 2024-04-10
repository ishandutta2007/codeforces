a,b = input().split(' ')
colors = int(b)
l = list(range(1,colors+1))*(int(100/colors)+5)
num = list(map(int,input().split(' ')))
if min(num)+colors < max(num):
    print("NO")
else:
    print("YES")
    for x in num:
        for n in range(x):
            print(l[n],end = ' ')
        print()