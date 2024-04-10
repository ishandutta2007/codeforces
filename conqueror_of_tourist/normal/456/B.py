n = int(input())
out = pow(1,n,5) + pow(2,n,5) + pow(3,n,5) + pow(4,n,5)
print(out % 5)