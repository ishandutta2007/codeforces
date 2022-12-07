def func():
    n,k = map(int,input().split())
    ss = 'a'
    for i in range(n-1):
        if ss[-1]=='a':
            ss += 'b'
        elif ss[-1]=='b':
            ss += 'c'
        elif ss[-1]=='c':
            ss += 'a'
    return ss


t = int(input())
arr = []
for _ in range(t):
    arr.append(func())

for i in range(t):
    print(arr[i])