for _ in range(int(input())):
    a, b = map(int, input().split())
    s = input()
    if(b == 0 or (s == s[::-1])):
        print(1)
    else:
        print(2)