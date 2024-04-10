for _ in range(int(input())):
    n = int(input())
    x = input()
    s = set()
    for i in x:
        s.add(i)
    print(n + len(s))