def check(s, k, t, n):
    # Check if the number s, but with last digit t, is k-beautiful.
    z = set()
    for i in range(len(s)):
        if(i == len(s)-1):
            z.add(t)
        else:
            z.add(int(s[i]))
    if(len(z)<=k):
        # Print the number
        needed = len(str(n)) - len(s)
        arr = []
        min_val = 9
        for i in range(len(s)):
            if(i == len(s)-1):
                arr.append(t)
                if(t < min_val):
                    min_val = t
            else:
                arr.append(int(s[i]))
                if(int(s[i])<min_val):
                    min_val = int(s[i])
        if(len(z)==k):
            for i in range(needed):
                arr.append(min_val)
        else:
            for i in range(needed):
                arr.append(0)
        for i in range(len(arr)):
            print(arr[i], end='')
        print()
        return True
    return False


def func(n, i, k):
    # Check for the number from 0 to i.
    s = str(n)[0:i+1]
    t = int(s[-1]) + 1
    # Check k-beauty of s for [t ---> 9]
    while(t < 10):
        if(check(s, k, t, n)):
            # print(s, k, t)

            return 0
        else:
            t += 1
    func(n, i-1, k)

for _ in range(int(input())):
    n, k = map(int, input().split())
    l = len(str(n))
    if(check(str(n), k, int(str(n)[-1]), n)):
        continue
    func(n, l-1, k)