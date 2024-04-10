def numline(f = int):
  return map(f, input().split())
    
n, k, x = numline()
a = [i for i in numline()]
    
print(sum(a[:len(a) - k]) + k * x)