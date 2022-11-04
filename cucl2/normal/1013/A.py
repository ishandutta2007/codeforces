n=int(input())
x=[int(n) for n in input().split(' ')]
y=[int(n) for n in input().split(' ')]
a=sum(x)
b=sum(y)
print(["No","Yes"][a>=b])