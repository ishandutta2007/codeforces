num = int(input())
rooms = []
for blarble in range(num):
    rooms.append(input().split(' '))
output = 0
for x in rooms:
    if int(x[1])-int(x[0])>=2:
        output += 1
print(output)