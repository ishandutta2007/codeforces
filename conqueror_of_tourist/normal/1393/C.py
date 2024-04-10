import heapq

T = int(input())
for test in range(T):
    n = int(input())
    l = dict()
    
    for v in map(int, input().split()):
        if v not in l:
            l[v] = 0
        l[v] += 1
    
    lo = 0 #Impossible
    hi = n #Possible
    
    while hi - lo > 1:
        test = (lo + hi) // 2
        
        so_far = []
        ll = dict(l)
        
        q = []
        works = True
        for v in l:
            heapq.heappush(q, -ll[v])
            
        for i in range(n):
            if i >= test:
                v = so_far[i-test]
                if v:
                    heapq.heappush(q, -v)
            if q:
                nex = -heapq.heappop(q)
                so_far.append(nex - 1)
            else:
                works = False
                break
        
        if works:
            lo = test
        else:
            hi = test
        
    print(lo - 1)