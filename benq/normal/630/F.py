n=int(input())
num5=int(n*(n-1)*(n-2)*(n-3)*(n-4)/120)
num6=int(n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)/720)
num7=int(n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)*(n-6)/5040)
print(num5+num6+num7)