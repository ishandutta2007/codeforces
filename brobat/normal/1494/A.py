def func():
    a = input()
    arr = []
    n = len(a)
    for i in range(n):
        arr.append(a[i])
    if(arr[0]==arr[n-1]):
        return "NO"
    A = arr[0]
    C = arr[n-1]
    Bpos = 0
    Bneg = 0
    for i in range(n):
        if(arr[i]==A):
            Bpos += 1
            Bneg += 1
        elif(arr[i]==C):
            Bpos -= 1
            Bneg -= 1
        else:
            Bpos += 1
            Bneg -= 1
        if(Bpos<0):
            Bpos = -52
        if(Bneg<0):
            Bneg = -52
    if(Bpos==0 or Bneg==0):
        return "YES"
    else:
        return "NO"

for _ in range(int(input())):
    print(func())