n = int(input())
string = input()
m11, m12, m21, m22 = 0, 0, 0, 0
for i in range(n):
    if i % 2 == 0 and string[i] == "b":
        m21 += 1
    elif i % 2 != 0 and string[i] == "r":
        m22 += 1
    elif i % 2 == 0:
        m11 += 1
    else:
        m12 += 1        
min1 = min(m21, m22)
m21, m22 = m21 - min1, m22 - min1
r1 = max(m21, m22) + min1
min2 = min(m11, m12)
m11, m12 = m11 - min2, m12 - min2
r2 = max(m11, m12) + min2
print(min(r1, r2))