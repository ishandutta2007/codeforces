n = int(input())
l = list(map(int, input().split()))

stack = []
ct = []
last = 0
out = 0

for i in range(n):
    #print(i,stack,ct,last,out)
    v = l[i]
    if i % 2 == 0:
        stack.append(v)
        ct.append(last)
    else:
        while v and stack:
            assert v > 0
            
            top = stack.pop()
            if v >= top:
                v -= top
                out += top
                ctp = ct.pop()
                out += ctp
                last = ctp + 1 
            else:
                out += v
                stack.append(top - v)
                v = 0
                last = 1
        if v:   
            last = 0

print(out)