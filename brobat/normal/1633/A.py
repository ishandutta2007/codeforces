for _ in range(int(input())):
    n = int(input())
    if(n % 7 == 0):
        print(n)
        continue
    s = str(n)
    if(len(s) == 1):
        print(7)
        continue
    arr = list()
    for i in range(len(s) - 1):
        arr.append(int(s[i]))
    for i in range(9):
        temp = ""
        for j in arr:
            temp += str(j)
        temp += str(i)
        if(int(temp) % 7 == 0):
            print(temp)
            break