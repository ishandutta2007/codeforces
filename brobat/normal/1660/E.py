for _ in range(int(input())):
    input()
    n = int(input())
    o = 0
    arr = list()
    for i in range(n):
        s = input()
        arr.append(s)
        o += s.count('1')
    best = 0
    for i in range(n):
        curr = 0
        for j in range(n):
            if(arr[j][(j + i)%n] == '1'):
                curr += 1
        best = max(best, curr)
    print(o - best + (n - best))