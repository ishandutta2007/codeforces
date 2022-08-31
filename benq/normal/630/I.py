n=int(input())
ans=0
ans += int(2*3*(4**(n-3)))
ans += int((n-3)*3*3*(4**(n-4)))
ans *= 4
print(ans)