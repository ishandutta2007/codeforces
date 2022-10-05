for _ in [0]*int(input()):
    n=int(input())
    s=input()
    if n%2:
        for c in s[::2]:
            if c in '13579':
                print(1)
                break
        else:
            print(2)
    else:
        for c in s[1::2]:
            if c in '24680':
                print(2)
                break
        else:
            print(1)