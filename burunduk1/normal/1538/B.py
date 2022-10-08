for cycle in range(int(input())):
    n = int(input())
    data = [int(x) for x in input().split()]
    mid = sum(data)/len(data)
    if mid != int(mid):
        print(-1)
    else:
        print(sum(i > mid for i in data))


# =mid
# <mid
# >mid   k=count(>mid)

# =====mid