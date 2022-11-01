n,m=gets.split(" ").map(&:to_i)
l,p=1,n
m.times{
    ls=gets.split(" ")
    if (ls[2]!="left")
        l=[l,(ls[4]).to_i+1].max
    else
        p=[p,(ls[4]).to_i-1].min
    end
}
puts l<=p ? p-l+1 : -1