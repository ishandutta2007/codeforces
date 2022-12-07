for _ in range(int(input())):
    s = input()
    if(len(s) <= 2):
        print(0)
        continue
    a = s.count('1')
    b = s.count('0')
    if(a == b):
        print(a - 1)
    else:
        print(min(a, b))