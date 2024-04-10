import sys
input = sys.stdin.buffer.readline
t = int(input())

for x in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    # a = list(map(int,input().split()))
    # b = list(map(int,input().split()))

    # score = sum(b)
    score = 0
    fire = [b[i] for i in range(n) if a[i]]
    frost = [b[i] for i in range(n) if not a[i]]

    # for  i in range(n):
    #     if(a[i] == 0):
    #         fire.append(b[i])
    #     else:
    #         frost.append(b[i])
    
    fire.sort(reverse=True)
    frost.sort(reverse=True)
    # k = len(fire)
    # l = len(frost)

    min_len = min(len(fire), len(frost))
    score += sum(fire[:min_len]*2 + frost[:min_len]*2 + fire[min_len:] + frost[min_len:])
    if(len(fire) == len(frost)):
        score -= min(b)
    
    print(score)