t=int(input())
for i in range(t):
    n, m=map(int, input().split())
    l=list(map(int, input().split())) 
    print(min(sum(l), m))