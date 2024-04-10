def p2pl(p1,p2,p3,p4,p5):
    prob0 = (1-p1)*(1-p2)*(1-p3)*(1-p4)*(1-p5)
    prob1 = p1*(1-p2)*(1-p3)*(1-p4)*(1-p5) + \
            p2*(1-p1)*(1-p3)*(1-p4)*(1-p5) + \
            p3*(1-p1)*(1-p2)*(1-p4)*(1-p5) + \
            p4*(1-p1)*(1-p2)*(1-p3)*(1-p5) + \
            p5*(1-p1)*(1-p2)*(1-p3)*(1-p4)
    return 1-(prob1+prob0)

n = int(input())
c1 = input().split(' ')
c1 = [int(c1[0]),int(c1[1])]

c2 = input().split(' ')
c2 = [int(c2[0]),int(c2[1])]

if n >= 3:
    c3 = input().split(' ')
    c3 = [int(c3[0]),int(c3[1])]
else:
    c3 = [0,0]

if n >= 4:
    c4 = input().split(' ')
    c4 = [int(c4[0]),int(c4[1])]
else:
    c4 = [0,0]

if n >= 5:
    c5 = input().split(' ')
    c5 = [int(c5[0]),int(c5[1])]
else:
    c5 = [0,0]

ans = 0
for x in range(1,10001):
    p1 = min(1,max(c1[1]-x+1,0)/(c1[1]-c1[0]+1))
    p2 = min(1,max(c2[1]-x+1,0)/(c2[1]-c2[0]+1))
    p3 = min(1,max(c3[1]-x+1,0)/(c3[1]-c3[0]+1))
    p4 = min(1,max(c4[1]-x+1,0)/(c4[1]-c4[0]+1))
    p5 = min(1,max(c5[1]-x+1,0)/(c5[1]-c5[0]+1))
    ans += p2pl(p1,p2,p3,p4,p5)
print(ans)