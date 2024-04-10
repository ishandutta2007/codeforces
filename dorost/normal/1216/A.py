n = int(input())
s = [*input()]
ans = 0
for i in range(0,n // 2) :
    if s[i * 2] == s[i * 2 + 1] :
        ans += 1
print(ans)
for i in range(0,n,2) :
    if s[i] == s[i + 1] :
        if s[i] == 'a':
            print("ba",end='')
        else :
            print("ab",end='')
    else:
        if s[i] == 'b':
            print("ba",end='')
        else :
            print("ab",end='')