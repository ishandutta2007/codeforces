n,m=map(int,input().split())
for _ in range(n):
    print(['#'*m,'.'*(m-1)+'#','#'*m,'#'+'.'*(m-1)][_%4])