def find(a, b):
    if b == 0:
        return 0
    return a/b + find(b, a%b)
    
x = map(int, raw_input().split())
print find(x[0], x[1])