def check(dat):
    mark = 0
    for i in range(6):
        if (dat[4 * i] == dat[4 * i + 1] and dat[4 * i] == dat[4 * i + 2] and dat[4 * i] == dat[4 * i + 3]):
            mark += 1
    if mark == 6:
        return True
    return False


## 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
data = list(map(int, input().split()))
for i in range(1):
    data2 = data.copy()
    data2[0] = data[14]
    data2[1] = data[12]
    data2[14] = data[11]
    data2[12] = data[10]
    data2[11] = data[17]
    data2[10] = data[19]
    data2[17] = data[0]
    data2[19] = data[1] 
    if(check(data2)):
        print("YES")
        exit(0)
        
    data2 = data.copy()
    data2[0] = data[17]
    data2[1] = data[19]
    data2[17] = data[11]
    data2[19] = data[10]
    data2[11] = data[14]
    data2[10] = data[12]
    data2[14] = data[0]
    data2[12] = data[1] 
    if(check(data2)):
        print("YES")
        exit(0)
    
        
    data2 = data.copy()
    data2[0] = data[4]
    data2[2] = data[6]
    data2[4] = data[8]
    data2[6] = data[10]
    data2[8] = data[23]
    data2[10] = data[21]
    data2[23] = data[0]
    data2[21] = data[2] 
    if(check(data2)):
        print("YES")
        exit(0)
        
    data2 = data.copy()
    data2[0] = data[23]
    data2[2] = data[21]
    data2[23] = data[8]
    data2[21] = data[10]
    data2[8] = data[4]
    data2[10] = data[6]
    data2[4] = data[0]
    data2[6] = data[2] 
    if(check(data2)):
        print("YES")
        exit(0)
    
    data2 = data.copy()
    data2[4] = data[16]
    data2[5] = data[17]
    data2[16] = data[20]
    data2[17] = data[21]
    data2[20] = data[12]
    data2[21] = data[13]
    data2[12] = data[4]
    data2[13] = data[5] 
    ##print(data2)
    if(check(data2)):
        print("YES")
        exit(0)
        
    data2 = data.copy()
    data2[4] = data[12]
    data2[5] = data[13]
    data2[12] = data[20]
    data2[13] = data[21]
    data2[20] = data[16]
    data2[21] = data[17]
    data2[16] = data[4]
    data2[17] = data[5] 
    if(check(data2)):
        print("YES")
        exit(0)
        

print("NO")