n = int(input())

out = 1
for i in range(n):
    out *= (i + 1)
    
out //= (n//2)
out //= (n//2)

print(out//2)