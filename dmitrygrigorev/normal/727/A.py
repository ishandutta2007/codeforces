def recursion(a, b):
    if b == a:
        return [a]
    if b == 0:
        return []
    if b % 2 == 0:
        s = recursion(a, b // 2)
        if len(s) > 0:
            return s + [b]
        else:
            return []
    elif b % 10 == 1:
        s = recursion(a, (b - 1) // 10) 
        if len(s) > 0:
            return s + [b]
        else:
            return []        
    else:
        return []
    
    
a, b = list(map(int, input().split()))
answer = recursion(a, b)
if len(answer) == 0:
    print("NO")
else:
    print("YES")
    print(len(answer))
    print(" ".join(map(str, answer)))